#pragma once
#include <wrl.h>
#include <windows.ui.xaml.media.dxinterop.h>
#include <winrt/Windows.UI.Xaml.Media.Imaging.h>
#include <d3d11.h>
#include <d2d1_1.h>
#include <thread>
#include <mutex>

namespace KinectProject
{

struct KinectFusionProcessor
{
	Microsoft::WRL::ComPtr<ISurfaceImageSourceNativeWithD2D> m_sisNativeWithD2D;
	Microsoft::WRL::ComPtr<ID3D11Device> m_d3dDevice;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_d3dDeviceContext;
	Microsoft::WRL::ComPtr<ID2D1Device> m_d2dDevice;
	Microsoft::WRL::ComPtr<ID2D1Bitmap> m_bitmap;

	bool m_processing;

	std::mutex processingLock;

	void SetupD3D(Microsoft::UI::Xaml::Media::Imaging::SurfaceImageSource* surfaceSource);
	void MainLoop();

};

}