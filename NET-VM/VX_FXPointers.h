#define VX_FX_UNITS 72

void (* VX_FX[VX_FX_UNITS])();


#include "vx_opcodes.h"

void initVXFX(){
 
  VX_FX[ADD]=add; // VX Arithmetic Subroutines
  VX_FX[SUB]=sub;
  VX_FX[MUL]=mul;
  VX_FX[DIV]=divd;
  VX_FX[MOD]=mod;
  
  VX_FX[AND]=and_op; // VX Logical Ops
  VX_FX[OR]=or_op;
  VX_FX[NOT]=not_op;
  VX_FX[XOR]=xor_op;
  VX_FX[NAND]=nand_op;
  VX_FX[NOR]=nor_op;
  VX_FX[XNOR]=xnor_op;
  
  VX_FX[PUSH]=push;
  VX_FX[POP]=pop;
  VX_FX[FSTA]=flush_stack;
  
  VX_FX[HLT]=halt;
  VX_FX[SLP]=sleep;
  VX_FX[RST]=sysrst;
  VX_FX[RVX]=reset_vx;

  VX_FX[JMP]=jmp;
  VX_FX[JZ]=jz;
  VX_FX[JE]=je;
  VX_FX[JNZ]=jnz;
  VX_FX[JL]=jl;
  VX_FX[JLE]=jle;
  VX_FX[JG]=jg;
  VX_FX[JGE]=jge;
  VX_FX[LP]=lp;
  VX_FX[LPZ]=lpz;
  VX_FX[LPE]=lpe;
  VX_FX[LPNZ]=lpnz;
  VX_FX[CMP]=cmp;

  VX_FX[CDR]=cdr;
  VX_FX[CRR]=crr;
  VX_FX[OUT]=outport;
  VX_FX[INP]=inport;
  VX_FX[RPL]=read_pin_level;
  VX_FX[SPL]=set_pin_level;
  VX_FX[SPM]=set_pin_mode;
  VX_FX[PWM]=pwm;
  VX_FX[RAN]=read_analog;
  VX_FX[SSP]=set_serial;
  VX_FX[JNE]=jne; // Jump if not equal
  
  VX_FX[FCOS]=fcos;
  VX_FX[FSIN]=fsin;
  VX_FX[FTAN]=ftan;
  VX_FX[FMAX]=fmax_;
  VX_FX[FSQR]=fsqr;
  VX_FX[FSQRT]=fsqrt;
  VX_FX[FMIN]=fmin_;
  VX_FX[FABS]=fabs_;
  VX_FX[SRND]=srnd;
  VX_FX[RND]=rnd;
  VX_FX[FADD]=fadd;
  VX_FX[FSUB]=fsub;
  VX_FX[FDIV]=fdiv;
  VX_FX[FMUL]=fmul;
  VX_FX[FPOW]=fpow;
  
  VX_FX[FCV]=fcv;
  VX_FX[FCR]=fcr;
  VX_FX[FPUSH]=fpush;
  VX_FX[FPOP]=fpop;
  
  VX_FX[INC]=inc;
  VX_FX[DCR]=dcr;

  VX_FX[SHL]=shl;
  VX_FX[SHR]=shr;
}
