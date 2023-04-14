#include "Controller.h"

Colours colour;
Controller::Controller() {

}
Controller::~Controller() {
	delete chosenCase_;
}

void Controller::click(ChessCase* button) {
	if(chosenPiece_ == nullptr) {
		if (button->getPiece() != nullptr) {
			chosenPiece_ = button->getPiece();
			chosenCase_ = button;
			chosenCase_->changeColor(colour.selectedCase);
		}
	}
	else {
		if(chosenPiece_ != button->getPiece()){
			button->setPiece(chosenPiece_);
			chosenCase_->deletePiece();
			chosenCase_->changeToBaseColour();
			chosenPiece_ = nullptr;
			chosenCase_ = nullptr;
		}
	}
}