/**
* Chess Game.
* \file   ChessCase.cpp
* \author Irem Yildiz
* \date   5 mai 2023
* Cr�� le 10 avril 2023
*/

#include "ChessCase.h"
#include "Controller.h"

ChessCase::ChessCase(int newX, int newY, std::shared_ptr<Controller> controller, QWidget* parent): x_(newX), y_(newY), controller_(controller), QPushButton(parent) {
    const QSize BUTTON_SIZE = QSize(lenght_, height_);
    setIconSize(QSize(iconLenght_, iconHeight_));
    setMinimumSize(BUTTON_SIZE);
    setMaximumSize(BUTTON_SIZE);
    connect(this, SIGNAL(clicked()), this, SLOT(handleButton()));
}

void ChessCase::setPiece(std::shared_ptr<PieceAbs> piece) {
    piece_ = piece;
    if (piece == nullptr)
        return;
    setIcon(QIcon(piece_->getIcon()));
    piece->setPos(x_, y_);
}
int ChessCase::getX() { return x_; }
int ChessCase::getY() { return y_; }

void ChessCase::handleButton() {
    controller_->click(this);
}

std::shared_ptr<PieceAbs> ChessCase::getPiece() {
    return piece_;
}

std::shared_ptr<PieceAbs> ChessCase::deletePiece() {
    std::shared_ptr<PieceAbs> oldPiece = std::move(piece_);
    setIcon(QIcon(""));
    return oldPiece;
}
void ChessCase::changeColor(QString colour) {
    setStyleSheet("background-color:" + (colour) + "; margin: -10px;");
}

void ChessCase::setBaseColour(QString colour) { colour_ = colour; }

void ChessCase::changeToBaseColour() { changeColor(colour_); }

QString ChessCase::getColour() { return colour_; }