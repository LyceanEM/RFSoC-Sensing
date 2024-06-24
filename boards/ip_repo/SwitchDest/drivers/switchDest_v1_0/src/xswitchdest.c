// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.2 (64-bit)
// Tool Version Limit: 2023.10
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xswitchdest.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XSwitchdest_CfgInitialize(XSwitchdest *InstancePtr, XSwitchdest_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Bus_a_BaseAddress = ConfigPtr->Bus_a_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XSwitchdest_Set_params(XSwitchdest *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSwitchdest_WriteReg(InstancePtr->Bus_a_BaseAddress, XSWITCHDEST_BUS_A_ADDR_PARAMS_DATA, Data);
}

u32 XSwitchdest_Get_params(XSwitchdest *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSwitchdest_ReadReg(InstancePtr->Bus_a_BaseAddress, XSWITCHDEST_BUS_A_ADDR_PARAMS_DATA);
    return Data;
}

