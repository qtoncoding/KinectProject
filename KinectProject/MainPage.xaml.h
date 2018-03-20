//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
#include "KinectFusionProcessor.h"

namespace KinectProject
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

		property Windows::UI::Xaml::Media::Imaging::SurfaceImageSource^ SurfaceSource;

	private:
		void Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		std::thread drawThread;
		KinectFusionProcessor processor;

		void threadProc();
	};
}
