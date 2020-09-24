/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector){
	*vec = finished_vector;
	av_turnaround_time = UNINITIALIZED;
	av_response_time = UNINITIALIZED;
	av_wait_time = UNINITIALIZED;
	Stats::calcStats();
}

void Stats::calcStats(){
	av_turnaround_time = UNINITIALIZED;
	av_response_time = UNINITIALIZED;
}

void Stats::showAllProcessInfo(){
	std::string out_string;
	int n = vec->size();
	for (int i = 0; i < n; i++){
		out_string += "Process " + std::to_string(i) + " Required CPU time:" + std::to_string(vec->front().required_cpu_time) +
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
