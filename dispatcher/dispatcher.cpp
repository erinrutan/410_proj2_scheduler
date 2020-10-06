/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */
#include "../includes/dispatcher.h"
#include "../includes/CPU.h"
#include "../includes/constants.h"
#include "../includes/PCB.h"

//pull current process (if any) off CPU and return it
//if nothing on CPU returns an uninitialized PCB
PCB Dispatcher::get_from_CPU() {
	PCB pcb_obj = cpu->get_process_off_core();
	is_valid_job_on_cpu = pcb_obj.process_number == UNINITIALIZED;
	return pcb_obj;
}

//place the current process on the CPU for execution
void Dispatcher::put_on_CPU(PCB  &process){
	cpu->get_process_off_core();
	cpu->put_process_on_core(process);
	is_valid_job_on_cpu = true;
}

//is CPU idle or working
bool Dispatcher::isValidJobOnCPU(){
	return is_valid_job_on_cpu;
}

