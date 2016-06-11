 //
// Copyright (c) 2015, Paul R. Swan
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
// OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
// TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
#include <LiquidCrystal.h>
#include <main.h>
#include <DFR_Key.h>
#include <zutil.h>

#include <C6802Cpu.h>
#include <CWmsSoundGame.h>

//
// The initial selector to select the game to test.
//
static SELECTOR s_gameSelector[] = {
  // "0123456789abcdef"
    {"- Set Repeat    ",  onSelectConfig, (void*) (&s_repeatSelectTimeInS),                             false},
    {"- Set Error     ",  onSelectConfig, (void*) (&s_repeatIgnoreError),                               false},
    {"Defender        ",  onSelectGame,   (void*) (CWmsSoundGame::createInstanceDefenderSound),         false},
    {"Stargate        ",  onSelectGame,   (void*) (CWmsSoundGame::createInstanceStargateSound),         false},
    {"Robotron        ",  onSelectGame,   (void*) (CWmsSoundGame::createInstanceRobotronSound),         false},
    {"Joust           ",  onSelectGame,   (void*) (CWmsSoundGame::createInstanceJoustSound),            false},
    {"Bubbles         ",  onSelectGame,   (void*) (CWmsSoundGame::createInstanceBubblesSound),          false},
    {"Sinistar Main   ",  onSelectGame,   (void*) (CWmsSoundGame::createInstanceSinistarMainSound),     false},
    {"Sinistar Aux    ",  onSelectGame,   (void*) (CWmsSoundGame::createInstanceSinistarAuxSound),      false},
    {"Splat           ",  onSelectGame,   (void*) (CWmsSoundGame::createInstanceSplatSound),            false},
    {"Firepower       ",  onSelectGame,   (void*) (CWmsSoundGame::createInstanceFirepowerSound),        false},
    {"Defender Pinball",  onSelectGame,   (void*) (CWmsSoundGame::createInstanceDefenderPinballSound),  false},
    {"Hyperball       ",  onSelectGame,   (void*) (CWmsSoundGame::createInstanceHyperballSound),        false},
    {"Varkon          ",  onSelectGame,   (void*) (CWmsSoundGame::createInstanceVarkonSound),           false},
    { 0, 0 }
};

void setup()
{
  mainSetup(s_gameSelector);
}

void loop()
{
  mainLoop();
}
