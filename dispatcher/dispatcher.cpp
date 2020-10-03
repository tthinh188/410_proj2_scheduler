/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 25, 2020
 *      Author: Thinh Phan
 */

#include "../includes/dispatcher.h"

// get current process
PCB Dispatcher::get_from_CPU(){
	is_valid_job_on_cpu = false; // job done
	return cpu->get_process_off_core();
}

void Dispatcher::put_on_CPU(PCB &process){
		cpu->put_process_on_core(process);  // put job on CPU
		is_valid_job_on_cpu = true; // notify job on CPU
}

// is it valid job ?
bool Dispatcher::isValidJobOnCPU(){
	return is_valid_job_on_cpu;
}
