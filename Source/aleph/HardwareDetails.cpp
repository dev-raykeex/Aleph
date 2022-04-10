// Fill out your copyright notice in the Description page of Project Settings.


#include "HardwareDetails.h"

FString UHardwareDetails::GetCPUBrand() {
	return FWindowsPlatformMisc::GetCPUBrand();
}

int32 UHardwareDetails::GetCPUCores() {
	return FWindowsPlatformMisc::NumberOfCores();
}

int32 UHardwareDetails::GetCPUThreads() {
	return FWindowsPlatformMisc::NumberOfCoresIncludingHyperthreads();
}

FString UHardwareDetails::GetGPUBrand() {
	return FWindowsPlatformMisc::GetPrimaryGPUBrand();
}

int32 UHardwareDetails::GetRAMCapacity() {
	return FGenericPlatformMemory::GetPhysicalGBRam();
}