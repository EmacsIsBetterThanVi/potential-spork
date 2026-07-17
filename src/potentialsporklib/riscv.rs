use crate::Memory;
use crate::CPU;
use std::mem::ManuallyDrop;
struct Isa32Core {
    ebreak: u32,
    ecall: u32,
    pc: u32,
    ra: u32,
    sp: u32,
    gp: u32,
    tp: u32,
    t0: u32,
    t1: u32,
    t2: u32,
    s0: u32,
    s1: u32,
    a0: u32,
    a1: u32,
    a2: u32,
    a3: u32,
    a4: u32,
    a5: u32,
    a6: u32,
    a7: u32,
    s2: u32,
    s3: u32,
    s4: u32,
    s5: u32,
    s6: u32,
    s7: u32,
    s8: u32,
    s9: u32,
    s10: u32,
    s11: u32,
    t3: u32,
    t4: u32,
    t5: u32,
    t6: u32,
}
pub struct Isa32<'a>{
    core: Isa32Core, 
    paused: bool,
    step: bool,
    ram: &'a mut dyn Memory
}
macro_rules! addrWrite {
    ( $($x:expr), *)
}
impl<'a> CPU<'a> for Isa32<'a>{
    fn reset(&mut self){
	unsafe {
	   let baddr: Isa32Array = Isa32Array { obj: ManuallyDrop::new(self.core) };
       	   for addr in 8..(8+(32*4)) {
	       
           }
       }
    }
    fn decode(&mut self){
       
    }
    fn execute(&mut self){
    }
    fn ramRegister(&mut self){
    }
    fn init(ram: &'a mut dyn Memory) -> Self{
	Self {
	    core: Isa32Core {
    ebreak: 0u32,
    ecall: 0u32,
    pc: 0u32,
    ra: 0u32,
    sp: 0u32,
    gp: 0u32,
    tp: 0u32,
    t0: 0u32,
    t1: 0u32,
    t2: 0u32,
    s0: 0u32,
    s1: 0u32,
    a0: 0u32,
    a1: 0u32,
    a2: 0u32,
    a3: 0u32,
    a4: 0u32,
    a5: 0u32,
    a6: 0u32,
    a7: 0u32,
    s2: 0u32,
    s3: 0u32,
    s4: 0u32,
    s5: 0u32,
    s6: 0u32,
    s7: 0u32,
    s8: 0u32,
    s9: 0u32,
    s10: 0u32,
    s11: 0u32,
    t3: 0u32,
    t4: 0u32,
    t5: 0u32,
		t6: 0u32,
	    },
    paused: false,
    step: false,
    ram,
       }
    }
}
