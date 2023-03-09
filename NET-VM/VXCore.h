bool VXExecutionPointers = false;

void initVXExecutionEngine(){
  if (! VXExecutionPointers){
      initVXFX();
      VXExecutionPointers = true;
  }

  VX_FX[VXInstructionDecoderUnit->opcode]();
  
}
