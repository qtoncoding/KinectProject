//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

#include <array>

using namespace KinectProject;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Media::Imaging;

using namespace Microsoft::WRL;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
	SurfaceSource = ref new SurfaceImageSource(640, 480);

	processor.SetupD3D(SurfaceSource);
	drawThread = std::thread(this->threadProc);
}


void KinectProject::MainPage::Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//ComPtr<ID2D1DeviceContext> drawingContext;
	//RECT drawRect{ 0, 0, 640, 480 };
	//POINT offset{ 0, 0 };
	//
	//if (auto hr = m_sisNativeWithD2D->BeginDraw(drawRect, 
	//											__uuidof(drawingContext), 
	//											&drawingContext, 
	//											&offset);
	//	hr == S_OK)
	//{
	//	drawingContext->Clear(D2D1::ColorF(D2D1::ColorF::Black));

	//	ComPtr<ID2D1SolidColorBrush> colorBrush;
	//	drawingContext->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Red), &colorBrush);
	//	drawingContext->DrawLine(D2D1_POINT_2F{ 50, 50 }, D2D1_POINT_2F{ 100, 200 }, colorBrush.Get());
	//	
	//	m_sisNativeWithD2D->EndDraw();
	//}
	//else
	//{
	//	// Lost device, bail!
	//}
}

void KinectProject::MainPage::threadProc()
{
	processor.MainLoop();
}
