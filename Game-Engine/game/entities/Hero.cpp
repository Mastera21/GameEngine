#include "game/entities/Hero.h"

//C system headers

//C++ system headers
#include <string>
#include <iostream>

//Other libraries headers

//Own components headers

int32_t Hero::init(int32_t heroRsrcId){

	_img.create(heroRsrcId, Point(400,200));

	return EXIT_SUCCESS;
}
void Hero::deinit(){

}
void Hero::draw(){
	_img.draw();
}
void Hero::handleEvent([[maybe_unused]]const sd::Event& event){

}
