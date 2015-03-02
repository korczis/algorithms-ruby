#encoding: utf-8

module Algorithms
  class << self
    def increment(x)
      fail 'x must be Fixnum' unless x.class == Fixnum

      if x == 0
        1
      elsif (x % 2) == 1
        2 * increment(x / 2)
      else
        x + 1
      end
    end
  end
end