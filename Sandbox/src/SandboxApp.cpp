#include <Sharon.h>

class ExampleLayer : public Sharon::Layer
{
public:
    ExampleLayer()
        : Layer("Example") { }

    void OnUpdate() override
    {
        SHARON_INFO("ExmpleLayer::Update");
    }

    void OnEvent(Sharon::Event& event) override
    {
        SHARON_TRACE("{0}", event);
    }
};

class Sandbox : public Sharon::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new Sharon::ImGuiLayer());
    }

    ~Sandbox()
    {

    }
};

Sharon::Application* Sharon::CreateApplication()
{
    return new Sandbox();
}