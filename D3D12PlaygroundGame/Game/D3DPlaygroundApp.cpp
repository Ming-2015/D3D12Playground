
#include "pch.h"
#include "D3D12PlaygroundGraphics/Public/Core/GameCore.h"

class D3D12PlaygroundApp : public Playground::GameCore::IGameApp
{
public:

    D3D12PlaygroundApp( void ) {}

    virtual void Startup( void ) override;
    virtual void Cleanup( void ) override;

    virtual void Update( float deltaT ) override;
    virtual void RenderScene( void ) override;

private:
};

void D3D12PlaygroundApp::Startup( void )
{

}

void D3D12PlaygroundApp::Cleanup( void )
{

}

void D3D12PlaygroundApp::Update( float deltaT )
{

}

void D3D12PlaygroundApp::RenderScene()
{

}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE /*hPrevInstance*/, _In_ LPWSTR /*lpCmdLine*/, _In_ int nCmdShow)
{
    return Playground::GameCore::RunApplication(D3D12PlaygroundApp(), L"Test", hInstance, nCmdShow);
}