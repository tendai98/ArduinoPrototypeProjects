#define VX_INSTRUCTION_SIZE 12
#define VX_ACTIVATOR 0xBEBE
#define ACTIVATOR_BYTE 0xBE
#define REGISTER_POPULATION 8
#define STACK_LIMIT 56
#define STACK_SIZE STACK_LIMIT*4*2
 
#define ACTIVATORS 2
#define GPIO_PINS 12
#define CPU_SIZE 80
#define MCU_HALT_DELAY 1000

#define MICRO_SEC 1
#define MILLI_SEC 2

#define INT_WRITE_MODE 0
#define FLOAT_WRITE_MODE 1
#define INT_READ_MODE 2
#define FLOAT_READ_MODE 3

unsigned int offset;
unsigned int load_offset=0;

struct float2Int{
  int value;
};

struct int2Float{
  float value;
};
  
struct VXBuffer{
  int IntStack[STACK_LIMIT];
} VXBufferUnit;

struct VXRegisterCore{
  
 int GPR32_Reg[REGISTER_POPULATION];    // 32
 float FLT32_Reg[REGISTER_POPULATION];  // 32
 unsigned int VXProgramCounter;         // 4
 unsigned int programSize;              // 4
 float analogInput;                     // 4
 unsigned char flagsRegister[4];        // 4
 
} VXRegisterCoreUnit;

struct VX_Decoder{
  unsigned short activator;
  unsigned short opcode;
  int operand1;
  int operand2;
};

struct VX_RawData{
  char rawdata[VX_INSTRUCTION_SIZE];
} VXRawData;

struct VX_Decoder * VXInstructionDecoderUnit;

// ==================================
struct float2Int * pushFloat;         // From Float to Stack Int
struct int2Float loadFloat;
// ========== [ STACK CAST] =========
struct int2Float * loadInt;           // From Int to Float
struct float2Int popFloat;
// ==================================

void VXBufferController(unsigned int bufferMode,unsigned int registerIndex,int bufferOffset){
  switch(bufferMode){
    
    case INT_WRITE_MODE:
     if ((bufferOffset < STACK_LIMIT) && (bufferOffset > -1)){
        VXBufferUnit.IntStack[bufferOffset]=VXRegisterCoreUnit.GPR32_Reg[registerIndex];
        
     }
     break;
      
    case INT_READ_MODE:
      if ((bufferOffset < STACK_LIMIT) && (bufferOffset > -1)){
        VXRegisterCoreUnit.GPR32_Reg[registerIndex]=VXBufferUnit.IntStack[bufferOffset];
    }
    break;

    case FLOAT_WRITE_MODE:
    if ((bufferOffset < STACK_LIMIT) && (bufferOffset > -1)){
        loadFloat.value = VXRegisterCoreUnit.FLT32_Reg[registerIndex];
        pushFloat = (struct float2Int *) &loadFloat;
        VXBufferUnit.IntStack[bufferOffset]=pushFloat->value;
     }
    break;

    case FLOAT_READ_MODE:
    if ((bufferOffset < STACK_LIMIT) && (bufferOffset > -1)){
        popFloat.value = VXBufferUnit.IntStack[bufferOffset];
        loadInt = (struct int2Float *) &popFloat;
        VXRegisterCoreUnit.FLT32_Reg[registerIndex]=loadInt->value;
     }
    break;
      
    default:
        break;
  }
}

#include "vx_fx.h"
#include "VX_FXPointers.h"
#include "VXCore.h"

void loadVXI(int rawDataLen){
  
  if (rawDataLen <= MAX_SIZE){
    
  VXRegisterCoreUnit.programSize=rawDataLen;
  
  for (VXRegisterCoreUnit.VXProgramCounter=0;VXRegisterCoreUnit.VXProgramCounter < rawDataLen;){
    
    if (recv_packet_buffer[VXRegisterCoreUnit.VXProgramCounter] == ACTIVATOR_BYTE){
      
        for (offset=VXRegisterCoreUnit.VXProgramCounter;offset< (VXRegisterCoreUnit.VXProgramCounter+VX_INSTRUCTION_SIZE) ;offset++){
          VXRawData.rawdata[load_offset]=recv_packet_buffer[offset];
          // Serial.print(recv_packet_buffer[offset],HEX);
          load_offset++;
        }
  
        VXInstructionDecoderUnit = (struct VX_Decoder *) &VXRawData;
        VXRegisterCoreUnit.VXProgramCounter+=VX_INSTRUCTION_SIZE;
        initVXExecutionEngine();
        load_offset=0;

    }
    
    }
  }
  
}
  
