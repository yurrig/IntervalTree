/******************************************************************************
**
** Copyright (C) 2020 Ivan Pinezhaninov <ivan.pinezhaninov@gmail.com>
**
** This file is part of the IntervalTree - Red-Black balanced interval tree
** which can be found at https://github.com/IvanPinezhaninov/IntervalTree/.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
** DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
** OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
** THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
******************************************************************************/

#include <iostream>

#include "intervaltree.hpp"


int main()
{
    // Create an interval tree
    Intervals::IntervalTree<int> intervalTree;

    // Insert intervals to the tree
    intervalTree.insert({20, 30});
    intervalTree.insert({40, 60});
    intervalTree.insert({70, 90});
    intervalTree.insert({60, 70});
    intervalTree.insert({40, 90});
    intervalTree.insert({80, 90});

    // Wanted interval and point
    auto wantedInterval = Intervals::Interval<int>(50, 80);
    auto wantedPoint = 50;

    // Find intervals
    const auto &overlappingIntervals = intervalTree.findOverlappingIntervals(wantedInterval);
    const auto &innerIntervals = intervalTree.findInnerIntervals(wantedInterval);
    const auto &outerIntervals = intervalTree.findOuterIntervals(wantedInterval);
    const auto &intervalsContainPoint = intervalTree.findIntervalsContainPoint(wantedPoint);

    // Print all intervals
    std::cout << "All intervals:" << std::endl;
    for (const auto &interval : intervalTree.intervals()) {
        std::cout << interval << std::endl;
    }
    std::cout << std::endl;

    // Print overlapping intervals
    std::cout << "Overlapping intervals for " << wantedInterval << ":" << std::endl;
    for (const auto &interval : overlappingIntervals) {
        std::cout << interval << std::endl;
    }
    std::cout << std::endl;

    // Print inner intervals
    std::cout << "Inner intervals for " << wantedInterval << ":" << std::endl;
    for (const auto &interval : innerIntervals) {
        std::cout << interval << std::endl;
    }
    std::cout << std::endl;

    // Print outer intervals
    std::cout << "Outer intervals for " << wantedInterval << ":" << std::endl;
    for (const auto &interval : outerIntervals) {
        std::cout << interval << std::endl;
    }
    std::cout << std::endl;

    // Print intervals contain the point
    std::cout << "Intervals contain a point value of " << wantedPoint << ":" << std::endl;
    for (const auto &interval : intervalsContainPoint) {
        std::cout << interval << std::endl;
    }

    return 0;
}
