#include "sharon_pch.h"
#include "OpenGLContext.h"
#include "GLFW/glfw3.h"
#include <glad/glad.h>

namespace Sharon
{
    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
        : m_WindowHandle(windowHandle)
    {
        SHARON_CORE_ASSERT(windowHandle, "Window handle is null!");
    }
    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        SHARON_CORE_ASSERT(status, "Failed to initialize Glad!");
    
        SHARON_CORE_INFO("OpenGL Vendor: {0}", glGetString(GL_VENDOR));
        SHARON_CORE_INFO("OpenGL Renderer: {0}", glGetString(GL_RENDERER));
        SHARON_CORE_INFO("OpenGL Version: {0}", glGetString(GL_VERSION));
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }
}