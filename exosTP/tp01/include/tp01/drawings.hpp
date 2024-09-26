#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shaders.hpp"
#include "colors.hpp"   


class Drawings {

public:
    Drawings() {

    }

    ~Drawings() {

    }

    static void changeBackgroundColor(float r, float g, float b, float a) {
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }


    /**
     * Dessine un rectangle de couleur chromatique (RGB gradient)
     * @param x coordonnée x du triangle (-1 : -1)
     * @param y coordonnée y du triangle (-1 : -1)
     * @param z coordonnée z du triangle (-1 : -1)
     */
    static void drawChromaRectangle(float x, float y, float z, float width, float height, bool rgbMode = true) {
        Shaders::useChromaColorShader();

        // Coords of the rectangle's vertices
		float rectangleVertices[] = {
			// positions            // colors
			x+width,  y, z, 	    0.0, 0.0f, (rgbMode ? 1.0f : 0.5f),  // top right
			x+width, y-height, z,  	(rgbMode ? 0.0f : 1.0f), (rgbMode ? 1.0f : 0.0f), (rgbMode ? 0.0f : 1.0f),  // bottom right
			x, y-height, z,  	    1.0f, (rgbMode ? 0.0f : 1.0f), 0.0f,  // bottom left
			x,  y, z,   	        (rgbMode ? 1.0f : 0.0f), (rgbMode ? 1.0f : 0.0f), (rgbMode ? 1.0f : 0.0f)   // top left 

		};


		// Rectangle's indices
		unsigned int rectangleIndices[] = {  // note that we start from 0!
			0, 1, 3,   // first triangle
			1, 2, 3    // second triangle
		}; 


        // Creation of a Element Buffer Object (EBO) to store the indices
        unsigned int rectangleEBO;
		glGenBuffers(1, &rectangleEBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rectangleEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rectangleIndices), rectangleIndices, GL_STATIC_DRAW); 



		// Creation of a Vertex Buffer Object (VBO) to store the vertices
		unsigned int rectangleVBO;
		glGenBuffers(1, &rectangleVBO); // Generate a buffer
		glBindBuffer(GL_ARRAY_BUFFER, rectangleVBO);  
		glBufferData(GL_ARRAY_BUFFER, sizeof(rectangleVertices), rectangleVertices, GL_STATIC_DRAW);


        // Creation of a Vertex Array Object (VAO)
		unsigned int VAO;
		glGenVertexArrays(1, &VAO); 

		// Link VBO to VAO
		glBindVertexArray(VAO);

		// Positions attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(0);	


        // Draw rectangle
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rectangleEBO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    }



    /**
     * Dessine un triangle de couleur chromatique (RGB gradient)
     * @param points first x,y,z of top point, second x,y,z of bottom right point, third x,y,z of bottom left point
     */
    static void drawChromaTriangle(float points[], bool rgbMode = true) {
        Shaders::useChromaColorShader();

        // // Coordonnées des points du triangle sur le rectangle
		// float triangleVertices[] = {
		// 	// positions                            // colors
		// 	points[0],  points[1], points[2], 		(rgbMode ? 1.0f : 0.0f), 0.0f, rgbMode ? 0.0f : 0.5f,  // top
		// 	points[3],  points[4], points[5],  	    (rgbMode ? 0.0f : 1.0f), 1.0f, 0.0f,  // bottom right
		// 	points[6],  points[7], points[8],     	(rgbMode ? 0.0f : 1.0f), 0.0f, 1.0f  // bottom left
		// };

         // Coordonnées des points du triangle sur le rectangle
		float triangleVertices[] = {
			// positions 
			points[0],  points[1], points[2],   // top
			points[3],  points[4], points[5],   // bottom right
			points[6],  points[7], points[8],   // bottom left
		};


		// Indices des points du triangle
		unsigned int triangleIndices[] = {  // note that we start from 0!
			0, 1, 2   // first triangle
		};

        unsigned int VBO;
        glGenBuffers(1, &VBO);


        unsigned int VAO;
        glGenVertexArrays(1, &VAO);  

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);  

        glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);  


        glBindVertexArray(VAO);


        glDrawArrays(GL_TRIANGLES, 0, 3);


		// Création d'un Vertex Buffer Object (VBO) pour stocker les vertices
		// unsigned int triangleVBO;
		// glGenBuffers(1, &triangleVBO); // Génère un buffer
		// glBindBuffer(GL_ARRAY_BUFFER, triangleVBO);
		// glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);


        // // Creation of an Element Buffer Object (EBO) to store the indices
        // unsigned int triangleEBO;
        // glGenBuffers(1, &triangleEBO);
		// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangleEBO);
		// glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangleIndices), triangleIndices, GL_STATIC_DRAW); 

        // unsigned int VAO;
        // glGenVertexArrays(1, &VAO); 
        // glBindVertexArray(VAO);

		// // Réaliser l'attribuation des données des vertices pour le triangle
		// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		// glEnableVertexAttribArray(0);
		// // color attribute
		// glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
		// glEnableVertexAttribArray(1);
		// glEnableVertexAttribArray(0);
		
        // glBindVertexArray(VAO);
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0);
        // glBindBuffer(GL_ARRAY_BUFFER, 0);
        // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    }

    /**
     * Dessine un triangle de couleur unique
     * @param points first x,y,z of top point, second x,y,z of bottom right point, third x,y,z of bottom left point
     * @param color couleur du triangle
     * @param a opacité du triangle
     */
    static void drawUnicolorTriangle(float points[], float r, float g, float b, float a) {
        Shaders::useSingleColorShader(r, g, b, a);

         // Coordonnées des points du triangle sur le rectangle
		float triangleVertices[] = {
			// positions 
			points[0],  points[1], points[2],   // top
			points[3],  points[4], points[5],   // bottom right
			points[6],  points[7], points[8],   // bottom left
		};


        unsigned int VBO;
        glGenBuffers(1, &VBO);

        unsigned int VAO;
        glGenVertexArrays(1, &VAO);  
        glBindVertexArray(VAO);
        
        glBindBuffer(GL_ARRAY_BUFFER, VBO);  
        glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);  

        glDrawArrays(GL_TRIANGLES, 0, 3);

    }

    /**
     * Dessine un triangle de couleur unie
     * @param points first x,y,z of top point, second x,y,z of bottom right point, third x,y,z of bottom left point
     * @param color couleur du triangle
     * @param a opacité du triangle
     */
    static void drawUnicolorTriangle(float points[], Colors color, float a) {
        Color c = getColor(color);
        drawUnicolorTriangle(points, c.r, c.g, c.b, a);
    }


};