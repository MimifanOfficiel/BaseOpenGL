#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <sstream>
#include <fstream>


class Shaders {

public:
    Shaders() {

    }
    ~Shaders() {

    }

    /**
     * Reads the glsl shader code from a file to make an object chroma colored 
     */
    static void useChromaColorShader() {
        // Lire le code du vertex shader depuis un fichier
		std::ifstream vertexShaderFile("resources/chroma/chromaVertexShader.vert");
		std::stringstream vertexShaderStream;
		vertexShaderStream << vertexShaderFile.rdbuf();
		std::string vertexShaderSource = vertexShaderStream.str();


		// Génération du shader
		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);


		// Compilation du shader
		const char* vertexShaderSourcePtr = vertexShaderSource.c_str();		
		glShaderSource(vertexShader, 1, &vertexShaderSourcePtr, NULL);		
		glCompileShader(vertexShader);


		// Vérification de la compilation du shader
		int  success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);


		// Si la compilation a échoué, on affiche l'erreur
		if(!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::CHROMA_COLOR::COMPILATION_FAILED" << infoLog << std::endl;
		}
		std::cout << "SUCCESS::SHADER::VERTEX::CHROMA_COLOR::COMPILATION_SUCCESS" << std::endl;



        // Lire le code du fragment shader depuis un fichier
		std::ifstream fragmentShaderFile("resources/chroma/chromaFragmentShader.frag");
		std::stringstream fragmentShaderStream;
		fragmentShaderStream << fragmentShaderFile.rdbuf();
		std::string fragmentShaderCode = fragmentShaderStream.str();
		const char* fragmentShaderSource = fragmentShaderCode.c_str();


		// Génération du shader
		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		// Compilation du shader
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);


		// Si la compilation a échoué, on affiche l'erreur
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if(!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::CHROMA_COLOR::COMPILATION_FAILED" << infoLog << std::endl;
		}
		std::cout << "SUCCESS::SHADER::FRAGMENT::CHROMA_COLOR::COMPILATION_SUCCESS" << std::endl;




		// Création du programme de shader
		unsigned int shaderProgram;
		shaderProgram = glCreateProgram();


		// Attacher les shaders au programme
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);


		// Si le linking a échoué, on affiche l'erreur
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if(!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED" << infoLog << std::endl;
		}
		std::cout << "SUCCESS::SHADER::PROGRAM::LINKING_SUCCESS" << std::endl;

		// Marquer les shaders à la suppression. Ils seront supprimés dès qu'il ne sont plus utilisés.
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

        // Utilisation du programme de shader
		glUseProgram(shaderProgram);
    }

    static void useSingleColorShader(float r, float g, float b, float a) {
        // Lire le code du vertex shader depuis un fichier
        std::ifstream vertexShaderFile("resources/singleColor/singleColorVertexShader.vert");
        std::stringstream vertexShaderStream;
        vertexShaderStream << vertexShaderFile.rdbuf();
        std::string vertexShaderCode = vertexShaderStream.str();
        const char* vertexShaderSource = vertexShaderCode.c_str();
        

        // Génération du shader
        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);


		// Compilation du shader
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);		
		glCompileShader(vertexShader);


		// Vérification de la compilation du shader
		int  success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);


		// Si la compilation a échoué, on affiche l'erreur
		if(!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::SINGLE_COLOR::COMPILATION_FAILED" << infoLog << std::endl;
		}
		std::cout << "SUCCESS::SHADER::VERTEX::SINGLE_COLOR::COMPILATION_SUCCESS" << std::endl;



        // Lire le code du fragment shader depuis un fichier
        std::ifstream fragmentShaderFile("resources/singleColor/singleColorFragmentShader.frag");
        std::stringstream fragmentShaderStream;
        fragmentShaderStream << fragmentShaderFile.rdbuf();
        std::string fragmentShaderCode = fragmentShaderStream.str();
        const char* fragmentShaderSource = fragmentShaderCode.c_str();

        
        // Génération du shader
		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		// Compilation du shader
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);


		// Si la compilation a échoué, on affiche l'erreur
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if(!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::SINGLE_COLOR::COMPILATION_FAILED" << infoLog << std::endl;
		}
		std::cout << "SUCCESS::SHADER::FRAGMENT::SINGLE_COLOR::COMPILATION_SUCCESS" << std::endl;


        // Création du programme de shader
        unsigned int shaderProgram;
        shaderProgram = glCreateProgram();
    

        // Attacher les shaders au programme
        glAttachShader(shaderProgram, vertexShader);        
        glAttachShader(shaderProgram, fragmentShader);        
        glLinkProgram(shaderProgram);   

        // Récupérer l'emplacement de la variable uniforme "color" dans le fragment shader
        GLint colorLocation = glGetUniformLocation(shaderProgram, "color");
        if (colorLocation == -1) {
            std::cerr << "ERROR::SHADER::UNIFORM::COLOR::NOT_FOUND" << std::endl;
        }


        
        // Si le linking a échoué, on affiche l'erreurche l'erre        
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);     
        if(!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::SINGLE_COLOR::LINKING_FAILED" << infoLog << std::endl;        
        }
        std::cout << "SUCCESS::SHADER::PROGRAM::SINGLE_COLOR::LINKING_SUCCESS" << std::endl;

        glDeleteShader(vertexShader);        
        glDeleteShader(fragmentShader);  

        glUseProgram(shaderProgram);
        glUniform4f(colorLocation, r, g, b, a);
        
        

    }

};