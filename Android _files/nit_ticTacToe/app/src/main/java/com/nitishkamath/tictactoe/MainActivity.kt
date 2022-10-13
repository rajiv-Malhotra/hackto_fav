package com.nitishkamath.tictactoe

import android.os.Bundle
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {


    var PLAYER = true
    var turn_count = 0

    //    boardStatus is use to check if bingo condition achieved or not
    var boardStatus = Array(3) { IntArray(3) }

    lateinit var board: Array<Array<Button>>

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        board = arrayOf(
            arrayOf(btn_one, btn_two, btn_three),
            arrayOf(btn_four, btn_five, btn_six),
            arrayOf(btn_seven, btn_eight, btn_nine)
        )

        for (item in board) {
            for (button in item) {
                button.setOnClickListener { this }
            }
        }


        boardStatusInit()

        btn_one.setOnClickListener {
            updateValue(row = 0, col = 0, player = PLAYER)
        }
        btn_two.setOnClickListener {
            updateValue(row = 0, col = 1, player = PLAYER)
        }
        btn_three.setOnClickListener {
            updateValue(row = 0, col = 2, player = PLAYER)
        }
        btn_four.setOnClickListener {
            updateValue(row = 1, col = 0, player = PLAYER)
        }
        btn_five.setOnClickListener {
            updateValue(row = 1, col = 1, player = PLAYER)
        }
        btn_six.setOnClickListener {
            updateValue(row = 1, col = 2, player = PLAYER)
        }
        btn_seven.setOnClickListener {
            updateValue(row = 2, col = 0, player = PLAYER)
        }
        btn_eight.setOnClickListener {
            updateValue(row = 2, col = 1, player = PLAYER)
        }
        btn_nine.setOnClickListener {
            updateValue(row = 2, col = 2, player = PLAYER)
        }
        btnReset.setOnClickListener {
            PLAYER = true
            turn_count = 0
            boardStatusInit()
            updateDisplay("Player X turn")
        }

//function ends here
    }

    private fun updateDisplay(text: String) {
        tvPlayer.text = text

    }

    private fun boardStatusInit() {
        for (i in 0..2) {
            for (j in 0..2) {
                boardStatus[i][j] = 0
            }
        }

        for (item in board) {
            for (button in item) {
                button.isEnabled = true
                button.text = ""
            }
        }
    }

    private fun updateValue(row: Int, col: Int, player: Boolean) {

        val text = if (player) "X" else "0"
        val value = if (player) 1 else -1
        board[row][col].apply {
            boardStatus[row][col] = value
            isEnabled = false
            setText(text)
        }

        turn_count++
        PLAYER = !PLAYER

        if (PLAYER)
            updateDisplay("Player X Turn")
        else
            updateDisplay("Player Y Turn")
        if (turn_count == 9)
            updateDisplay("Game Draw")

        checkWinner()
    }

    private fun checkWinner() {
        for (i in 0..2) {
            for (j in 0..2) {
                if ((boardStatus[i][0] == boardStatus[i][1]) && (boardStatus[i][0] == boardStatus[i][2])) {
                    if (boardStatus[i][0] == 1) {
                        updateDisplay("X is Winner")
                        disableButton()
                    } else if (boardStatus[i][0] == -1) {
                        updateDisplay("Y is Winner")
                        disableButton()
                    }
                } else if ((boardStatus[0][j] == boardStatus[1][j]) && (boardStatus[0][j] == boardStatus[2][j])) {
                    if (boardStatus[0][j] == 1) {
                        updateDisplay("X is Winner")
                        disableButton()
                    } else if (boardStatus[0][j] == -1) {
                        updateDisplay("Y is Winner")
                        disableButton()
                    }
                }
            }
            if ((boardStatus[0][0] == boardStatus[1][1]) && (boardStatus[0][0] == boardStatus[2][2])) {
                if (boardStatus[0][0] == 1) {
                    updateDisplay("X is Winner")
                    disableButton()
                } else if (boardStatus[0][0] == -1) {
                    updateDisplay("Y is Winner")
                    disableButton()
                }
            } else if ((boardStatus[0][2] == boardStatus[1][1]) && (boardStatus[0][2] == boardStatus[2][0])) {
                if (boardStatus[0][2] == 1) {
                    updateDisplay("X is Winner")
                    disableButton()
                } else if (boardStatus[0][2] == -1) {
                    updateDisplay("Y is Winner")
                    disableButton()
                }
            }
        }

    }

    private fun disableButton() {
        for (i in 0..2) {
            for (j in 0..2) {
                board[i][j].apply {
                    isEnabled = false;
                }

            }
        }
    }


}