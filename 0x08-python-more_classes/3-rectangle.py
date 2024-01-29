#!/usr/bin/python3
"""Rectangle class definition"""


class Rectangle:
    """This is a rectangle class
    Attributes:
        __width (int): width of a rectangle
        __height (int): height of a rectangle
    """
    def __init__(self, width=0, height=0):
        """Initializes the rectangle
        Args:
            width (int): the width of the rectangle
            height (int): the height of the rectangle
        Returns:
            None
        """
        self.width = width
        self.height = height

    @property
    def width(self):
        """getter of __width
        Returns:
            the width of the rectangle
        """
        return self.__width

    @width.setter
    def width(self, value):
        """setter of __width
        Args:
            value (int): the width of a rectangle
        Return:
            None
        """
        if type(value) is not int:
            raise TypeError("width must be an integer")
        else:
            if value < 0:
                raise ValueError("width must be >= 0")
            else:
                self.__width = value

    @property
    def height(self):
        """getter of __height
        Returns:
            the height of the rectangle
        """
        return self.__height

    @height.setter
    def height(self, value):
        """setter of __height
        Args:
            value (int): the height of a rectangle
        Returns:
            None
        """
        if type(value) is not int:
            raise TypeError("height must be an integer")
        else:
            if value < 0:
                raise ValueError("height must be >= 0")
            else:
                self.__height = value

    def area(self):
        """calculates the area of the rectangle
        Returns:
            the area of the rectangle
        """
        return (self.__height * self.__height)

    def perimeter(self):
        """calculates the perimeter of the rectangle
        Returns:
            the perimeter of the rectangle
        """
        if self.__width == 0 or self.__height == 0:
            return 0
        else:
            return (self.__width * 2) + (self.__height * 2)

    def __str__(self):
        """returns printable string representation of the rectangle
        Returns:
            printable string representation of a rectangle
        """
        string = ""
        if self.__width != 0 and self.__height != 0:
            string += "\n".join("#" * self.__width
                                for i in range(self.__height))
        return string
