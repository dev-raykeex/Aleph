// Fill out your copyright notice in the Description page of Project Settings.


#include "ConsoleWindow.h"

#include "GenericPlatform/GenericPlatformOutputDevices.h"

void UConsoleWindow::ReadFromFile()
{
	FOutputDevice* OutputDevice = FGenericPlatformOutputDevices::GetLog();
	if(OutputDevice != nullptr)
	{
		OutputDeviceFile = static_cast<FOutputDeviceFile*>(OutputDevice);
		LogFile = OutputDeviceFile->GetFilename();
	}
	OutputDeviceFile->Flush();
	if (FFileHelper::LoadANSITextFileToStrings(*LogFile, NULL, LogArray))
	{
		bLoadFileStatus = true;
	} else
	{
		bLoadFileStatus = false;
	}
}

