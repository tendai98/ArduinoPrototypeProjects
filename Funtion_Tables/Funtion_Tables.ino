#define MAX_INT_REGISTERS 10
#define INSTRUCTION_LEN 5
#define MAX_INSTRUCTION_BUFFER 50
#define MAX_VM_OPS 11

struct VirtualCPURegisters{
  short R[MAX_INT_REGISTERS];
  short IP;
  byte currOpcode;
};

struct CODEC{
  short v1;
  short v2;
  char data[4];
};

struct VirtualCPURegisters cpu;
struct CODEC * cdx;

void ( * VM_OPS[MAX_VM_OPS] )();

void ADD(){ cpu.R[cdx->v1] += cpu.R[cdx->v2]; Serial.print("ADD "); }
void SUB(){ cpu.R[cdx->v1] -= cpu.R[cdx->v2]; Serial.print("SUB "); }
void MUL(){ cpu.R[cdx->v1] *= cpu.R[cdx->v2]; Serial.print("MUL "); }
void DIV(){ cpu.R[cdx->v1] /= cpu.R[cdx->v2]; Serial.print("DIV "); }
void MOD(){ cpu.R[cdx->v1] %= cpu.R[cdx->v2]; Serial.print("MOD "); }
void AND(){ cpu.R[cdx->v1] &= cpu.R[cdx->v2]; Serial.print("AND "); }
void LOR(){ cpu.R[cdx->v1] |= cpu.R[cdx->v2]; Serial.print("LOR "); }
void XOR(){ cpu.R[cdx->v1] ^= cpu.R[cdx->v2]; Serial.print("XOR "); }
void NOT(){ cpu.R[cdx->v1] = !cpu.R[cdx->v2]; Serial.print("NOT "); }
void CRR(){ cpu.R[cdx->v1] = cpu.R[cdx->v2]; Serial.print("CRR "); }
void CDR(){ cpu.R[cdx->v1] = cdx->v2; Serial.print("CDR "); }

void resetVCPU(){

    VM_OPS[0x0]=ADD;
    VM_OPS[0x1]=SUB;
    VM_OPS[0x2]=MUL;
    VM_OPS[0x3]=DIV;
    VM_OPS[0x4]=MOD;
    VM_OPS[0x5]=AND;
    VM_OPS[0x6]=LOR;
    VM_OPS[0x7]=XOR;
    VM_OPS[0x8]=NOT;
    VM_OPS[0x9]=CDR;
    VM_OPS[0xA]=CRR;
    cpu.IP=0;
    
    for (int i = 0; i < MAX_INT_REGISTERS ; i++ ){
      cpu.R[i]=0;
    }
}

// Simple E-VX (Embedded Virtual Execution) Program
// This is an abstract instruction set running in a simple VM

char Buffer[MAX_INSTRUCTION_BUFFER] = 
/*     ___________________________________________________     
      |VM Binary Code            |   VM Code Disassembly  |
      |--------------------------|------------------------|      */      
    "\x09\x00\x00\x10\x00" //|   CDR R0,16
    "\x09\x01\x00\x20\x00" //|   CDR R1,32
    "\x00\x00\x00\x01\x00" //|   ADD R0,R1
    "\x0A\x02\x00\x00\x00" //|   CRR R2,R0
    "\x0A\x03\x00\x02\x00" //|   CRR R3,R2
    "\x02\x03\x00\x02\x00" //|   MUL R3,R2
    "\x03\x03\x00\x00\x00" //|   DIV R3,R0
    "\x05\x00\x00\x00\x00" //|   AND R0,R0
    "\x07\x02\x00\x02\x00" //|   XOR R2,R2
    "\x06\x01\x00\x00\x00" //|   LOR R1,R0
;

char CVMI[INSTRUCTION_LEN-1]={0};

void runVCPU(){
  short offset = 0;
  
  for (cpu.IP = 0 ; cpu.IP < MAX_INSTRUCTION_BUFFER;){
     cpu.currOpcode = Buffer[cpu.IP+0];
     CVMI[offset+0] = (char) Buffer[cpu.IP+1];
     CVMI[offset+1] = (char) Buffer[cpu.IP+2];
     CVMI[offset+2] = (char) Buffer[cpu.IP+3];
     CVMI[offset+3] = (char) Buffer[cpu.IP+4];
     
     cdx = (struct CODEC *) CVMI;
     VM_OPS[cpu.currOpcode]();
     
     Serial.print(" ");
     Serial.print(cpu.R[0]);
     Serial.print(" ");
     Serial.print(cpu.R[1]);
     Serial.print(" ");
     Serial.print(cpu.R[2]);
     Serial.print(" ");
     Serial.print(cpu.R[3]);
     
     Serial.print(" OPERANDS = ");
     Serial.print(cdx->v1);
     Serial.print(" ");
     Serial.print(cdx->v2);
     Serial.print(" RAW OPS = ");
     Serial.print(HEX,CVMI[0]);
     Serial.print(" ");
     Serial.print(HEX,CVMI[1]);
     Serial.print(" ");
     Serial.print(HEX,CVMI[2]);
     Serial.print(" ");
     Serial.print(HEX,CVMI[3]);
     Serial.println();
     
     cpu.IP += 5;
     
    delay(1000);
  }
  
}

void setup() {
    Serial.begin(9600);
    resetVCPU();
}

void loop(){
    runVCPU();
    resetVCPU();
    delay(1000);
}
