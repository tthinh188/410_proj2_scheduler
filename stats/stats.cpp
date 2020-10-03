/*
 * Stats.cpp
 *
 *  Created on: Sep 25, 2020
 *      Author: Thinh Phan
 */

#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector) {
	vec = new std::vector<PCB>(finished_vector);
	av_turnaround_time = UNINITIALIZED;
	av_response_time = UNINITIALIZED;
	av_wait_time = UNINITIALIZED;
	calcStats();
}
void Stats::calcStats(){
	// UNINITIALIZED = -5, then set them to 0
	av_response_time = 0;
	av_turnaround_time = 0;
	av_wait_time = 0;
	int size = vec->size();
	for (int i = 0; i < size; i++){
		av_response_time += (vec->back().start_time - vec->back().arrival_time);
		av_turnaround_time += (vec->back().finish_time - vec->back().arrival_time);
		av_wait_time += (vec->back().finish_time - vec->back().arrival_time - vec->back().required_cpu_time);
		vec->pop_back();
	}
	av_response_time = av_response_time / size;
	av_turnaround_time = av_turnaround_time  / size;
	av_wait_time = av_wait_time / size;
}

void Stats::showAllProcessInfo(){
	std::string out_string = "";
	int size = vec->size();
	for (int i = 0; i < size; i++){
		out_string += "Process " + std::to_string(i+1) + " Required CPU time:" + std::to_string(vec->front().required_cpu_time) +
				" arrived:" + std::to_string(vec->front().arrival_time) + " started: " +
				std::to_string(vec->front().start_time) + " finished:" + std::to_string(vec->front().finish_time) +"\n";
	}
	std::cout << out_string;
}

float Stats::get_av_response_time(){
	return av_response_time;
}
float Stats::get_av_turnaround_time(){
	return av_turnaround_time;
}

float Stats::get_av_wait_time(){
	return av_wait_time;
}
