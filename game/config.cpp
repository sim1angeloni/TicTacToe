/****************************************************************************************
** Copyright (C) 2016-2018 Simone Angeloni
** This file is part of Tic Tac Toe.
**
** Tic Tac Toe is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** Tic Tac Toe is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Tic Tac Toe. If not, see <http://www.gnu.org/licenses/>
**
****************************************************************************************/

#include "stdafx.h"
#include "config.hpp"

namespace Game {
	namespace Config {

		void waitBooleanInput(const std::string & text, bool & output)
		{
			std::string input;
			char inputChar = 0;

			do
			{
				std::cout << text;
				std::cin >> input;

				inputChar = input.at(0);
			} while (inputChar != 'y' && inputChar != 'Y' && inputChar != 'n' && inputChar != 'N');

			output = (inputChar == 'y' || inputChar == 'Y');
		}

		void config(TicTacToe::GameParams & params)
		{
			waitNumericInput<unsigned int>("Board width", 3, 9, params.boardWidth);
			waitNumericInput<unsigned int>("Board height", 3, 9, params.boardHeight);

			unsigned int playersNum = 0;
			waitNumericInput<unsigned int>("Players number", 2, 6, playersNum);

			params.players.resize(playersNum);
			for (unsigned int i = 0; i < playersNum; ++i)
			{
				std::ostringstream text;
				text <<  "Is Player" << i << " human [y-n]? ";

				bool val = false;
				waitBooleanInput(text.str(), val);
				params.players[i] = val;
			}

			waitNumericInput<unsigned int>("Number of contiguous cells to win", 3, std::min(params.boardWidth, params.boardHeight), params.winConditionCells);
			waitNumericInput<unsigned int>("Number of unavailable cells", 0, (params.boardHeight * params.boardWidth) - 1, params.unavailableCells);
		}

	} // namespace Config
} // namespace Game
