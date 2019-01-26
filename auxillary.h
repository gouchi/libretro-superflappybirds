#ifndef LR_SUPERFLAPPYBIRDS_AUXILLARY_H
#define LR_SUPERFLAPPYBIRDS_AUXILLARY_H

#include <stack>

class Auxillary {
public:
    /// Returns a stack with each digit of a number in order.
    /// i.e., 356 -> [3, 5, 6]
    /// \param number The number to seperate into digits.
    /// \return The stack of digits.
    static std::stack<int> digits(int number) {
        std::stack<int> sd;
        while (number > 0) {
            int digit = number % 10;
            number /= 10;
            sd.push(digit);
        }
        if (sd.empty())
            sd.push(0);

        return sd;
    }

    /// Gets the frames for each digit to be drawn.
    /// \param number The number to be drawn.
    /// \param number_frames The frames for each number on the texture, in order.
    /// \param x The x position to be drawn at.
    /// \param y The y position to be drawn at.
    /// \param pixels_between_numbers The gap in pixels between the digits.
    /// \return The frames, each pair consists of the src and dest frame.
    static std::vector<std::pair<SDL_Rect, SDL_Rect>> getNumberRects(int number, std::vector<SDL_Rect>* number_frames, int x, int y, int pixels_between_numbers) {
        auto ds = digits(number);
        int x_offset = 0;
        std::vector<std::pair<SDL_Rect, SDL_Rect>> positions;
        while (!ds.empty())
        {
            int digit = ds.top();
            ds.pop();
            SDL_Rect frame = number_frames->at(digit);
            SDL_Rect dest_rect;
            dest_rect.x = x + x_offset;
            dest_rect.y = y;
            dest_rect.w = frame.w;
            dest_rect.h = frame.h;
            positions.push_back({frame, dest_rect});
            x_offset += frame.w + pixels_between_numbers;
        }
        return positions;
    }
};

#endif //LR_SUPERFLAPPYBIRDS_AUXILLARY_H
