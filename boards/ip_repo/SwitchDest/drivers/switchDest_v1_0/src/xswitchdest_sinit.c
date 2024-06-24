// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.2 (64-bit)
// Tool Version Limit: 2023.10
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xswitchdest.h"

extern XSwitchdest_Config XSwitchdest_ConfigTable[];

#ifdef SDT
XSwitchdest_Config *XSwitchdest_LookupConfig(UINTPTR BaseAddress) {
	XSwitchdest_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XSwitchdest_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XSwitchdest_ConfigTable[Index].Bus_a_BaseAddress == BaseAddress) {
			ConfigPtr = &XSwitchdest_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XSwitchdest_Initialize(XSwitchdest *InstancePtr, UINTPTR BaseAddress) {
	XSwitchdest_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XSwitchdest_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XSwitchdest_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XSwitchdest_Config *XSwitchdest_LookupConfig(u16 DeviceId) {
	XSwitchdest_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XSWITCHDEST_NUM_INSTANCES; Index++) {
		if (XSwitchdest_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XSwitchdest_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XSwitchdest_Initialize(XSwitchdest *InstancePtr, u16 DeviceId) {
	XSwitchdest_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XSwitchdest_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XSwitchdest_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

