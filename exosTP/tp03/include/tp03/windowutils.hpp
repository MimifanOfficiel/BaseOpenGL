#ifndef WinDOW_UTIls
#define WinDOW_UTIls

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <imgui.h>
#include <imgui-1.91.1/backends/imgui_impl_opengl3.h>
#include <imgui-1.91.1/backends/imgui_impl_glfw.h>
#include <imgui-1.91.1/backends/imgui_impl_dx11.h>
#include <imgui-1.91.1/backends/imgui_impl_win32.h>

#include <glengine/orbitalCamera.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


size_t SCR_WIDTH = 800;
size_t SCR_HEIGHT = 600;


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


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}


void cursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
    if (ImGui::GetIO().WantCaptureMouse) return;  // Ignore mouse movement if ImGui is using the mouse

    if (mouseButtonState == MousePressedButton::NONE) {
        lastX = (float)xpos;
        lastY = (float)ypos;
    } else {
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
            default:
                break;
        }
    }
}


void onMouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (ImGui::GetIO().WantCaptureMouse) return;  // Ignore mouse clicks if ImGui is using the mouse

    if (action == GLFW_RELEASE) {
        mouseButtonState = MousePressedButton::NONE;
    } else {
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
if (ImGui::GetIO().WantCaptureMouse) return;  // Ignore scroll events if ImGui is using the mouse
    orbitalCamera.zoom((float)yoffset);
}


#endif