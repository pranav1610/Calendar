# Calendar

## Introduction
I compiled my knowledge of Data Structures & Algorithms to develop a GUI Calendar software allowing event management.

## Demo
https://youtu.be/1fllEsKAJBU

## Details
1. Features
   * Save or add events(birthdays, tasks)
   * Preview and highlight days having birthdays, tasks, or both throughout the month.
   * Remove events by looking up the event name
   * Customize to Night or Light view, and also save the view as a .png file.

1. Data Structures
   1. N-Ary Trees to allow Menu expansion to a tree view.
   2. Stacks to allow undo/redo triggered events through keyboard shortcuts
   3. Maps to generate & store months(and its events) using a dropdown.
   4. Vectors to store multiple events in a day.
   5. Doubly-linked lists to enable real-time typing with backspace ability.

1. Usage & setup
   1. Clone the master repository (git clone https://github.com/pranav1610/Calendar.git)
   2. Install C++ and a compiler([Visual Studio](https://visualstudio.microsoft.com/downloads/), [G++](https://gcc.gnu.org/), etc.)
   3. Install SFML [here](https://www.sfml-dev.org/download/sfml/2.5.1/), and follow their [setup instructions](https://www.sfml-dev.org/tutorials/2.5/start-vc.php)
   4. Build & run.
   5. Enjoy!

## Preview
##### Main view:
![main](https://user-images.githubusercontent.com/77756530/146632339-d08d5ba3-887b-4977-9f8b-0c26cc60ff9f.jpeg)

##### Adding events:
![date](https://user-images.githubusercontent.com/77756530/146632355-58ce5bf9-7147-4007-b060-5404db45de22.jpeg)

##### Highlight events in a light view:
![highlight](https://user-images.githubusercontent.com/77756530/146632381-2b78e591-3add-44bc-8a9c-1a2d0a3dd8db.jpeg)

## Launch
* C++ 14
* Visual C++ 2019
* SFML 2.5.1

## Status:
Complete

[Back to top](#)
