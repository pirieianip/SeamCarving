Name: Ian Pirie
Date: 4/30/2020
Program: SeamCarving

Requirements: Threads package or pthreads

To compile Program:
    1. navigate to cmake-build-debug in the
    2. enter "cmake .."
    3. enter "make"

To run Program:
    1. navigate to cmake-build-debug
    2. run "./SeamCarving name_of_file number_of_vertical_seams number_of_horizontal_seams"

This is a fairly functional approach to Seam Carving. There should be very little to no state.

The SeamCarvingLib is similar to a C style class. The helpers are more utility functions to help
deal with reading cmdline args and file input/ output. It also allows for translating the adjacency
list so there is no need for a second implementation of seam carving.

In main, it checks whether there are more lines wanting to be carved then there are lines in the
image file to end gracefully. It creates the adjacency list, processes vertical seams, rotates
the adjacency list 90 degrees, processes horizontal seams then rotates to original orientation.
Once reoriented, it outputs to file_processed.pgm.

I wish I could put this in a more parallel setup but it seams rather linear in processing without
adding a lot of memory bloat. That being said, it does run rather swiftly.

