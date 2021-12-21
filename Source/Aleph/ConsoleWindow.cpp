// Fill out your copyright notice in the Description page of Project Settings.


#include "ConsoleWindow.h"

#include "GenericPlatform/GenericPlatformOutputDevices.h"

void UConsoleWindow::PrintLogInConsole()
{
	FOutputDevice* OutputDevice = FGenericPlatformOutputDevices::GetLog();
	if(OutputDevice != nullptr)
	{
		OutputDeviceFile = static_cast<FOutputDeviceFile*>(OutputDevice);
		LogFile = OutputDeviceFile->GetFilename();
	}
	OutputDeviceFile->Flush();
	if (FFileHelper::LoadFileToString(LogContent, *LogFile, FFileHelper::EHashOptions::None, 4))
	{
	}
}