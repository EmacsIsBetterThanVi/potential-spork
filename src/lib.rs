pub mod emulator_core{
    pub trait Memory {
    	fn get_8(&self, addr: usize) -> u8;
	fn set_8(&mut self, addr: usize, value: u8);
	fn get_16(&self, addr: usize, big: bool) -> u16{
	    if (big){
	       return ((self.get_8(addr) as u16)<<8) | (self.get_8(addr+1) as u16);
	    } else {
	       return ((self.get_8(addr+1) as u16)<<8) | (self.get_8(addr) as u16);
	    }
	 }
	 fn get_32(&self, addr: usize, big: bool) -> u32{
	    if (big){
	       return ((self.get_8(addr) as u32)<<24) | ((self.get_8(addr+1) as u32)<<16)| ((self.get_8(addr+2) as u32)<<8) | (self.get_8(addr+3) as u32);
	    } else {
	    	    return ((self.get_8(addr+3) as u32)<<24) | ((self.get_8(addr+2) as u32)<<16)| ((self.get_8(addr+1) as u32)<<8) | (self.get_8(addr) as u32) ;
	    }
	 }
	 fn get_64(&self, addr: usize, big: bool) -> u64{
	    if (big){
	       return ((self.get_8(addr) as u64)<<56) + ((self.get_8(addr+1) as u64)<<48) | ((self.get_8(addr+2) as u64)<<40)| ((self.get_8(addr+3) as u64)<<32) | ((self.get_8(addr+4) as u64)<<24) | ((self.get_8(addr+5) as u64)<<16)| ((self.get_8(addr+6) as u64)<<8) | (self.get_8(addr+7) as u64);
	    } else {
	       return ((self.get_8(addr+7) as u64)<<56) + ((self.get_8(addr+6) as u64)<<48) | ((self.get_8(addr+5) as u64)<<40)| ((self.get_8(addr+4) as u64)<<32) | ((self.get_8(addr+3) as u64)<<24) | ((self.get_8(addr+2) as u64)<<16)| ((self.get_8(addr+1) as u64)<<8) | (self.get_8(addr) as u64);
	    }
	 }
    }
    pub struct RAM {
    	data: Vec<u8>
    }
    pub struct ROM{
    	data: Vec<u8>
    }
    impl Memory for RAM{
	 fn get_8(&self, addr: usize) -> u8{
	    self.data[addr]
	 }
	 fn set_8(&mut self, addr: usize, value: u8){
	    self.data[addr] = value;
	 }
   }
   impl RAM{
	 fn new(length: usize) -> Self {
	    RAM{
	    	data: vec![0; length]
	    }
	 }
    }
    impl Memory for ROM {
	 fn get_8(&self, addr: usize) -> u8{
	    self.data[addr]
	 }
	 fn set_8(&mut self, addr: usize, value: u8){
	 
	 }
    }
    impl ROM {
    	 fn new(length: usize) -> Self {
	    ROM{
	    	data: vec![0; length]
	    }
	 }
    }
    pub struct MemMap<'a>{
    	regions: Vec<&'a dyn Memory>,
	big_endian: bool
    }
    impl MemMap<'_>{
    	 fn new(big_endian: bool) -> Self{
	    Self {
	    	 regions: Vec::<&dyn Memory>::new(),
		 big_endian
	    }
	 }
    }
}
pub mod potentialsporklib;