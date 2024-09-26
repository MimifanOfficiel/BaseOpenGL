#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <sstream>
#include <fstream>

#include <tp01/learnopengl_shaders.hpp>
#include <tp01/drawings.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stbimage/stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glengine/orbitalCamera.hpp>
#include <imgui.h>


double cursorX, cursorY;
bool drawRectangle = false;

float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame



unsigned scr_width = 800;
unsigned scr_height = 600;

// Plan proche et lointain
const float near_plane = 0.1f;
const float far_plane = 10.0f;

// État de la souris
bool firstMouse = true;
float lastX;
float lastY;

enum class MousePressedButton { NONE, LEFT, RIGHT, MIDDLE };
MousePressedButton mouseButtonState = MousePressedButton::NONE;
GLEngine::OrbitalCamera orbitalCamera(glm::vec3(0.3f, 0.4f, 3.0f), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));


/* Caméra

glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
const float cameraSpeed = 0.05f; // adjust accordingly


bool firstMouse = true;
float yaw   = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
float pitch =  0.0f;
float lastX =  800.0f / 2.0;
float lastY =  600.0 / 2.0;
float fov   =  45.0f;

*/

// Permet de remodifier le viewport à chaque fois que les dimensions de la fenêtre sont changées
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
} 

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
    /*cursorX = xpos;
    cursorY = ypos;

	if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
  
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; 
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw   += xoffset;
    pitch += yoffset;

    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(direction);*/

	if (mouseButtonState == MousePressedButton::NONE) {
    lastX = (float)xpos;
    lastY = (float)ypos;
  }
  else {
    if (firstMouse) {
      lastX = xpos;
      lastY = ypos;
      firstMouse = false;
    }

    float xoffset = (float)xpos - lastX;
    float yoffset = lastY - (float)ypos;

    lastX = (float)xpos;
    lastY = (float)ypos;

    switch (mouseButtonState) {
      case MousePressedButton::LEFT: orbitalCamera.orbit(xoffset, yoffset);
        break;
      case MousePressedButton::RIGHT:
        orbitalCamera.track(xoffset);
        orbitalCamera.pedestal(yoffset);
        break;
      case MousePressedButton::MIDDLE: orbitalCamera.dolly(yoffset);
        break;
    }
  }
}


void onMouseButton(GLFWwindow* window, int button, int action, int mods) {
  if (action == GLFW_RELEASE) {
      mouseButtonState = MousePressedButton::NONE;
  }
  else {
    switch (button) {
      case GLFW_MOUSE_BUTTON_LEFT: mouseButtonState = MousePressedButton::LEFT;
        break;
      case GLFW_MOUSE_BUTTON_RIGHT: mouseButtonState = MousePressedButton::RIGHT;
        break;
      case GLFW_MOUSE_BUTTON_MIDDLE: mouseButtonState = MousePressedButton::MIDDLE;
        break;
    }
  }
}



void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    /*fov -= (float)yoffset;
	std::cout << fov << std::endl;
    if (fov < 1.0f) fov = 1.0f;
    if (fov > 45.0f) fov = 45.0f; */
	if (!ImGui::GetIO().WantCaptureMouse) {
    	orbitalCamera.zoom((float)yoffset);
  	}
}



// Fonction qui permet de gérer les entrées clavier
void processInput(GLFWwindow *window) {

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        
		glfwSetWindowShouldClose(window, true); // Envoie l'instruction à GLFW de fermer la fenêtre

	} 

	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
        if (!drawRectangle) { // Si le rectangle n'est pas déjà dessiné
            drawRectangle = true;
        }
    } else {
        drawRectangle = false; // Réinitialiser l'état si la touche n'est pas pressée
    }

	/*float cameraSpeed = static_cast<float>(2.5 * deltaTime);

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) cameraPos += cameraSpeed * cameraFront;
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) cameraPos -= cameraSpeed * cameraFront;
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) cameraPos += cameraSpeed * cameraUp;
	if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) cameraPos -= cameraSpeed * cameraUp;*/


}


int main() {

    // ça part de là !
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // On essaie de créer la fenêtre, si ça ne marche pas on arrête
    GLFWwindow* window = glfwCreateWindow(800, 600, "Lila BRANDON TP 1", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }


    // On créer le contexte OpenGL avec la fenêtre créée
    glfwMakeContextCurrent(window);
	ImGui::CreateContext();


    // Essayer d'initialiser GLAD, si ce n'est pas réussi on arrête
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }  


    // On modifie le viewport pour qu'il corresponde à la taille de la fenêtre
    // 1er param : coordonnée X de l'origine de la fenêtre
    // 2e param : coordonnée Y de l'origine de la fenêtre
    // 3e param : largeur de la fenêtre
    // 4e param : hauteur de la fenêtre
    glViewport(0, 0, 800, 600);


    // Appeler la fonction qui modifie le viewport à chaque fois que l'on modifie la taille de la fenêtre
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  


	glEnable(GL_DEPTH_TEST); 


	glfwSetCursorPosCallback(window, cursorPosCallback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetMouseButtonCallback(window, onMouseButton);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);



	// On charge les shaders



	Shader ourShader("resources/textured/texturedVertexShader.vert", "resources/textured/texturedFragmentShader.frag"); 



	float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };


	glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);



	unsigned int texture1;
	glGenTextures(1, &texture1);  
	glBindTexture(GL_TEXTURE_2D, texture1);  

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned char *data = stbi_load("resources/images/container.jpg", &width, &height, &nrChannels, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	} else {
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);


	unsigned int texture2;
	glGenTextures(1, &texture2);  
	glBindTexture(GL_TEXTURE_2D, texture2);  

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);  
	unsigned char *data2 = stbi_load("resources/images/awesomeface.png", &width, &height, &nrChannels, 0);
	if (data2) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	stbi_image_free(data2);




	ourShader.use();
	ourShader.setInt("texture1", 0);
    ourShader.setInt("texture2", 1);


	 




    // Boucle de rendu, elle ne s'arrêtera que lorsqu'on dira à GLFW de s'arrêter.
    while(!glfwWindowShouldClose(window)) {

		processInput(window); // Fonction qui gère les entrées clavier


		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;  

		/*glm::mat4 projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);  
		ourShader.setMat4("projection", projection); */
		glm::mat4 projection = glm::perspective(orbitalCamera.getFov(), (float)scr_width / (float)scr_height, near_plane, far_plane);
		ourShader.setMat4("projection", projection);

		glm::mat4 view = orbitalCamera.getViewMatrix();
		ourShader.setMat4("view", view);



		// Commandes de rendu ici
		// Drawings::changeBackgroundColor(0.2f, 0.3f, 0.3f, 1.0f);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

        // bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);


		ourShader.use();
      
		
		/*glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        ourShader.setMat4("view", view);*/


        // render boxes
        glBindVertexArray(VAO);
        for (unsigned int i = 0; i < 10; i++)
        {
            // calculate the model matrix for each object and pass it to shader before drawing
            glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            ourShader.setMat4("model", model);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }







		// glBindVertexArray(VAO);
        // glDrawArrays(GL_TRIANGLES, 0, 36);



		// // Coordonnées des points du triangle sur le rectangle
		// float triangleVertices[] = {
		// 	// positions
		// 	0.0f,  0.9f, 0.0f, 		
		// 	0.5f,  -0.1f, 0.0f,  	
		// 	-0.5f, -0.1f, 0.0f
		// };


		// float triangleVertices2[] = {
		// 	// positions
		// 	0.0f,  0.3f, 0.0f, 		
		// 	0.5f,  -0.7f, 0.0f,  	
		// 	-0.5f, -0.7f, 0.0f
		// };


		// Drawings::drawChromaRectangle(-0.5f, 0.9f, 0.0f, 0.3f, 0.2f, true);
		// Drawings::drawChromaRectangle(-0.5f, 0.4f, 0.0f, 0.6f, 0.4f, false);

		
		// //Drawings::drawChromaTriangle(triangleVertices, true);
		// Drawings::drawUnicolorTriangle(triangleVertices, 0.0f, 0.0f, 1.0f, 1.0f);
		// Drawings::drawUnicolorTriangle(triangleVertices2, Colors::Beige, 0.4f);

		// if (drawRectangle) {
        //     Drawings::drawChromaRectangle(cursorX / 800.0f * 2.0f - 1.0f, -cursorY / 600.0f * 2.0f + 1.0f, 0.0f, 0.6f, 0.5f, false);
        // }

		
        glfwSwapBuffers(window); //will swap the color buffer (a large 2D buffer that contains color values for each pixel in GLFW's window) that is used to render to during this render iteration and show it as output to the screen.
        glfwPollEvents();    	 // Checks if any events are triggered (keyboard input or mouse movement), updates window state, calls the corresponding functions (which we can register via callback methods).
	
	}

	glfwTerminate();

    return 0;
}

