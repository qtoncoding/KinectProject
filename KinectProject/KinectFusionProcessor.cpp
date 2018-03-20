#include "pch.h"
#include "KinectFusionProcessor.h"

void KinectProject::KinectFusionProcessor::SetupD3D(Microsoft::UI::Xaml::Media::Imaging::SurfaceImageSource^ surfaceSource)
{
	auto sisInspectable = reinterpret_cast<IInspectable*>(surfaceSource);
	sisInspectable->QueryInterface(__uuidof(ISurfaceImageSourceNativeWithD2D), static_cast<void**>(&m_sisNativeWithD2D));

	auto flags = D3D11_CREATE_DEVICE_FLAG::D3D11_CREATE_DEVICE_BGRA_SUPPORT |
		D3D11_CREATE_DEVICE_FLAG::D3D11_CREATE_DEVICE_VIDEO_SUPPORT;

	std::array<D3D_FEATURE_LEVEL, 4> featureLevels = { D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_12_1,
		D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_12_0,
		D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_11_0 };

	D3D11CreateDevice(nullptr,
					  D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_HARDWARE,
					  nullptr,
					  flags,
					  featureLevels.data(),
					  featureLevels.size(),
					  D3D11_SDK_VERSION,
					  &m_d3dDevice,
					  nullptr,
					  &m_d3dDeviceContext);

	ComPtr<IDXGIDevice> dxgiDevice;
	m_d3dDevice.As(&dxgiDevice);

	ComPtr<ID3D10Multithread> d3dMultithread;
	m_d3dDevice->QueryInterface(__uuidof(ID3D10Multithread), static_cast<void**>(&d3dMultithread));
	d3dMultithread->SetMultithreadProtected(TRUE);

	D2D1CreateDevice(dxgiDevice.Get(), nullptr, &m_d2dDevice);

	m_sisNativeWithD2D->SetDevice(m_d2dDevice.Get());
}

void KinectProject::KinectFusionProcessor::MainLoop()
{
	OutputDebugString(L"Start draw thread");
	bool running = true;
	while (running)
	{
		{
			std::unique_lock<std::mutex>(page->m_processingLock);
			if (!page->m_processing)
			{
				running = false;
			}
		}


	}
	OutputDebugString(L"Stop draw thread");
}