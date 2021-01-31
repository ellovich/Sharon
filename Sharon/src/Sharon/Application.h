#pragma once
#include "Core.h"

#include "Window.h"
#include "LayerStack.h"
#include "Events/ApplicationEvent.h"

#include "Sharon/ImGui/ImGuiLayer.h"

// temp
#include <Renderer/Shader.h>

namespace Sharon
{
    class SHARON_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }
    
        inline static Application& Get() { return *s_Instance; }

    private:
        bool OnWindowClose(WindowClosedEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        // temp
        unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
        std::unique_ptr<Shader> m_Shader;

    private:
        static Application* s_Instance;
    };

    // to be defined in a CLIENT
    Application* CreateApplication();
}