# AliensFromOuterSpace
A simple action game which uses SFML and C++. In the game, we guide a small space ship to fight off alien invaders until the ship is destroyed or we achieve a score limit. There are power-ups in the game that aid the player by receiving health pickups or upgrading the ship's weapons and speed.

## Demo
Demo gameplay of this game can be watched on YouTube by clicking [here](https://www.youtube.com/watch?v=YAaQ5-neJmI).

## Report
Further documentation and insight into the development of this game can be found in the attached `Report.pdf` file.

## Issues
The enemy spawner bases on a tick loop which depends on the actual processing speed of the CPU. In the cases of modern, quicker CPUs, the difficulty rises quickly as the enemies simply spawn way quicker than the player is able to react. The fix is simple - just base the tick loop on the actual system time.
