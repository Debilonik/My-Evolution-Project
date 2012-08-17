====================
My-Evolution-Project
====================

It's just my first real Qt and C++ experience.

Previously based on https://github.com/tucnak/conway project.

I'm sending great gratitude to Tuchak for his repo and article on Habrahabr.ru !

====================

My Evolution Project is small application that generates cells (3 types) and checks collisions between them.
Controls:
    Use left click to add and change cells and right click to erase cells.
    Use Enter to Start/Pause simulation.
Rules of Evolution (combinations):
    2 Black cells make Green cell;
    2 Green make Red;
    2 Red do nothing;
    1 Black + 1 Green make Black;
    Red cells eat all other around them in 4 directions.
    Red cell dies if it didn't ate someshint within 20 steps of generation. 
Setting: 
    Universe Size - size of universe :) The number of rows and columns of cells.
    Generations interval - time before next generation will be shown.

====================

License: Hmm.. Free for all, but tell me, it'll be pretty pleasant :)