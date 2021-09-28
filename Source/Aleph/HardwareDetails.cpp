// Fill out your copyright notice in the Description page of Project Settings.


#include "HardwareDetails.h"
#include "Kismet/GameplayStatics.h"

FString UHardwareDetails::GetCPUBrand() {
	if (PLATFORM_WINDOWS) {
		return FWindowsPlatformMisc::GetCPUBrand();
	} else if (PLATFORM_LINUX || PLATFORM_MAC || PLATFORM_MAC_ARM64) {
		return FGenericPlatformMisc::GetCPUBrand();
	}
}

FString UHardwareDetails::GetGPUBrand() {
	if (PLATFORM_WINDOWS) {
		return FWindowsPlatformMisc::GetPrimaryGPUBrand();
	} else if(PLATFORM_LINUX || PLATFORM_MAC || PLATFORM_MAC_ARM64) {
		return FGenericPlatformMisc::GetPrimaryGPUBrand();
	}
}

int32 UHardwareDetails::GetCPUCores() {
	if (PLATFORM_WINDOWS) {
		return FWindowsPlatformMisc::NumberOfCores();
	} else if (PLATFORM_LINUX || PLATFORM_MAC || PLATFORM_MAC_ARM64) {
		return FGenericPlatformMisc::NumberOfCores();
	}
}

int32 UHardwareDetails::GetCPUThreads() {
	if (PLATFORM_WINDOWS) {
		return FWindowsPlatformMisc::NumberOfCoresIncludingHyperthreads();
	} else if (PLATFORM_LINUX || PLATFORM_MAC || PLATFORM_MAC_ARM64) {
		return FGenericPlatformMisc::NumberOfCoresIncludingHyperthreads();
	}
}

int32 UHardwareDetails::GetRAMCapacity() {
	return FGenericPlatformMemory::GetPhysicalGBRam();
}