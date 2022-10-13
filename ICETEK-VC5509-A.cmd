-w
-stack 500
-sysstack 500
-l rts55x.lib

MEMORY 
{
    DARAM:	o=0x100,	l=0x07f00
    VECT :  o=0x0d000,	l=0x100
    DARAM2: o=0x0d100,	l=0x1f00
    SARAM:  o=0x10000,	l=0x30000
    SDRAM:	o=0x40000,	l=0x3e0000
}

SECTIONS
{
    .text:    {} > DARAM 
    .vectors: {} > VECT 
    .trcinit: {} > DARAM 
    .gblinit: {} > DARAM 
     frt:     {} > DARAM 
    
    .cinit:   {} > DARAM 
    .pinit:   {} > DARAM 
    .sysinit: {} > DARAM 
    .bss:     {} > DARAM2 
    .far:     {} > DARAM2 
    .const:   {} > DARAM 
    .switch:  {} > DARAM 
    .sysmem:  {} > DARAM 
    .cio:     {} > DARAM 
    .MEM$obj: {} > DARAM 
    .sysheap: {} > DARAM 
    .sysstack {} > DARAM 
    .stack:   {} > DARAM 
    
}


