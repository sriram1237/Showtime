/**
 * Name        : ShowTime
 * Version     : 
 * Vendor      : 
 * Description : 
 */


#include "ShowTime.h"
#include "ShowTimeFrame.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

ShowTimeApp::ShowTimeApp(void)
{
}

ShowTimeApp::~ShowTimeApp(void)
{
}

UiApp*
ShowTimeApp::CreateInstance(void)
{
	// Create the instance through the constructor.
	return new ShowTimeApp();
}

bool
ShowTimeApp::OnAppInitializing(AppRegistry& appRegistry)
{
	// TODO:

	// Create a Frame
	ShowTimeFrame* pShowTimeFrame = new ShowTimeFrame;
	pShowTimeFrame->Construct();
	pShowTimeFrame->SetName(L"ShowTime");
	AddFrame(*pShowTimeFrame);


	// TODO: Add your initialization code here
	return true;
}

bool
ShowTimeApp::OnAppInitialized(void)
{
	// TODO:
	// Comment.
	return true;
}

bool
ShowTimeApp::OnAppWillTerminate(void)
{
	// TODO:
	// Deallocate or release resources that are UI dependent.
	return true;
}

bool
ShowTimeApp::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	// TODO:
	// Deallocate resources allocated by this App for termination.
	// The App's permanent data and context can be saved via appRegistry.
	return true;
}

void
ShowTimeApp::OnForeground(void)
{
	// TODO:
	// Start or resume drawing when the application is moved to the foreground.
}

void
ShowTimeApp::OnBackground(void)
{
	// TODO:
	// Stop drawing when the application is moved to the background.
}

void
ShowTimeApp::OnLowMemory(void)
{
	// TODO:
	// Free unused resources or close the application.
}

void
ShowTimeApp::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
	// TODO:
	// Handle any changes in battery level here.
	// Stop using multimedia features(camera, mp3 etc.) if the battery level is CRITICAL.
}

void
ShowTimeApp::OnScreenOn(void)
{
	// TODO:
	// Get the released resources or resume the operations that were paused or stopped in OnScreenOff().
}

void
ShowTimeApp::OnScreenOff(void)
{
	// TODO:
	// Unless there is a strong reason to do otherwise, release resources (such as 3D, media, and sensors) to allow the device
	// to enter the sleep mode to save the battery.
	// Invoking a lengthy asynchronous method within this listener method can be risky, because it is not guaranteed to invoke a
	// callback before the device enters the sleep mode.
	// Similarly, do not perform lengthy operations in this listener method. Any operation must be a quick one.
}
