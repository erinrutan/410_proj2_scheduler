/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */
#include "../includes/dispatcher.h"


PCB pcb_obj;

//pull current process (if any) off CPU and return it
//if nothing on CPU returns an uninitialized PCB
PCB Dispatcher::get_from_CPU() {
	return pcb_obj;
}

//place the current process on the CPU for execution
void Dispatcher::put_on_CPU(PCB  &process){

}

//is CPU idle or working
bool Dispatcher::isValidJobOnCPU(){
	return false;
}

