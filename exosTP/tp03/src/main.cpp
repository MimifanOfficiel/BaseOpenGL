#include <tp03/windowutils.hpp>
#include <tp03/learnopengl_shaders.hpp>
#include <tp03/config.hpp>

#include <iostream>

#include <vector>


int main() {

    // SETUP GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // SETUP GLFW WINDOW
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Lila BRANDON TP 2", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // SETUP WINDOW CONTEXT
    glfwMakeContextCurrent(window);

    // CRASH IF UNABLE TO INIT GLAD
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // SETUP VIEWPORT AND EVENT HANDLERS
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 
    glfwSetCursorPosCallback(window, cursorPosCallback);
    glfwSetMouseButtonCallback(window, onMouseButtonCallback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

    glEnable(GL_DEPTH_TEST);


    ///////////////////////////////////////////////////////////////
    ///                   SETTING UP IM GUI                     ///
    ///////////////////////////////////////////////////////////////

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io; // Init ImGui IO

    // Setup Dear ImGui style
    ImGui::StyleColorsLight();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls    

    
    
    ///////////////////////////////////////////////////////////////
    ///                     OBJECT LOADING                      ///
    ///////////////////////////////////////////////////////////////

    std::vector<float> vertices;
    std::vector<unsigned int> faces;

    std::ifstream file(std::string(_resources_directory).append("objects/dragon2_smooth.obj"));
    if (!file.is_open()) {
        std::cerr << "Failed to open bunny.obj" << std::endl;
        return -1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "v") {
            float x, y, z;
            iss >> x >> y >> z;
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
        } else if (prefix == "f") {
            unsigned int v1, v2, v3;
            iss >> v1 >> v2 >> v3;
            // -1 parce que les indices des .obj commencent à 1 et non 0
            faces.push_back(v1 - 1); 
            faces.push_back(v2 - 1);
            faces.push_back(v3 - 1);
        }
    }

    file.close();

    std::cout << "Loaded " << vertices.size() / 3 << " vertices and " << faces.size() / 3 << " faces" << std::endl;


    unsigned int VAO, VBO, EBO;


    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, faces.size() * sizeof(unsigned int), faces.data(), GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


    // Récupérer les données de vérification des buffers (exemple pour les vertices)
    // float vertexCheck[vertices.size()];
    // glGetBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(float), vertexCheck);
    // for (int i = 0; i < vertices.size(); i++) {
    //     if (vertices[i] != vertexCheck[i]) {
    //         std::cerr << "Buffer data is not the same" << vertices[i] << " vs " << vertexCheck[i] << std::endl;
    //         // return -1;
    //     }
    // }


    Shader shader(std::string(_resources_directory).append("shaders/objects.vert").c_str(), std::string(_resources_directory).append("shaders/objects.frag").c_str());

    shader.use();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);



    while(!glfwWindowShouldClose(window)) {

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();


        // Settings Window
        ImGui::Begin("Settings");
        // ImGui::ColorEdit4("Edges Color", (float*)&edgeColor);
        // ImGui::SliderFloat("Line Thickness", &lineThickness, 0.0f, 0.35f);

        ImGui::End();
        ImGui::Render();

        shader.use();


        glm::mat4 projection = glm::perspective(orbitalCamera.getFov(), (float)SCR_WIDTH / (float)SCR_HEIGHT, near_plane, far_plane);
        shader.setMat4("projection", projection);
        glm::mat4 view = orbitalCamera.getViewMatrix();
        shader.setMat4("view", view);

        // glm::mat4 model = glm::mat4(1.0f);
        // model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f)); 
        // shader.setMat4("model", model);

        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)); // Le mettre plus loin de la caméra
        shader.setMat4("model", model);


		glBindVertexArray(VAO); // NE PAS OUBLIER CA, IDIOTE
        glDrawElements(GL_TRIANGLES, faces.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);


		glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        


        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return EXIT_SUCCESS;
}