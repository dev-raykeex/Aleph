// Fill out your copyright notice in the Description page of Project Settings.


#include "HardwareDetails.h"
#include "HardwareInfo.h"
#include "Kismet/GameplayStatics.h"

FString UHardwareDetails::GetCPUBrand() {
	if (PLATFORM_WINDOWS) {
		return FWindowsPlatformMisc::GetCPUBrand();
	} else if (!PLATFORM_WINDOWS) {
		return FGenericPlatformMisc::GetCPUBrand();
	}
}

FString UHardwareDetails::GetGPUBrand() {
	if (PLATFORM_WINDOWS) {
		return FWindowsPlatformMisc::GetPrimaryGPUBrand();
	} else if(!PLATFORM_WINDOWS) {
		return FGenericPlatformMisc::GetPrimaryGPUBrand();
	}
}

FString UHardwareDetails::GetRHI()
{
	return FHardwareInfo::GetHardwareInfo(NAME_RHI);
}

int32 UHardwareDetails::GetCPUCores() {
	if (PLATFORM_WINDOWS) {
		return FWindowsPlatformMisc::NumberOfCores();
	} else if (!PLATFORM_WINDOWS) {
		return FGenericPlatformMisc::NumberOfCores();
	}
}

int32 UHardwareDetails::GetCPUThreads() {
	if (PLATFORM_WINDOWS) {
		return FWindowsPlatformMisc::NumberOfCoresIncludingHyperthreads();
	} else if (!PLATFORM_WINDOWS) {
		return FGenericPlatformMisc::NumberOfCoresIncludingHyperthreads();
	}
}

int32 UHardwareDetails::GetRAMCapacity() {
	return FGenericPlatformMemory::GetPhysicalGBRam();
}