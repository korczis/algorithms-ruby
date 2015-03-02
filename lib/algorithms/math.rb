#encoding: utf-8

module Algorithms
  class << self
    def find_min_float(val = 1.0)
      res = val / 2
      res != 0.0 ? find_min_float(res) : val
    end
  end
end