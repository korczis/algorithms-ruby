# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'algorithms/version'

Gem::Specification.new do |spec|
  spec.name          = "algorithms-ruby"
  spec.version       = Algorithms::VERSION
  spec.authors       = ["Tomas Korcak"]
  spec.email         = ["korczis@gmail.com"]

  if spec.respond_to?(:metadata)
    # spec.metadata['allowed_push_host'] = "TODO: Set to 'http://mygemserver.com' to prevent pushes to rubygems.org, or delete to allow pushes to any server."
  end

  spec.summary       = 'Algorithms in pure ruby'
  spec.description   = 'Fundamental algorithms in ruby'
  spec.homepage      = "http://github.com/korczis/algorithms-ruby"
  spec.license       = "MIT"

  spec.files         = `git ls-files -z`.split("\x0").reject { |f| f.match(%r{^(test|spec|features)/}) }
  spec.bindir        = ['bin']
  spec.executables   = ['algorithms-ruby']
  spec.require_paths = ["lib"]

  spec.extensions = %w[ext/algorithms/extconf.rb]

  spec.add_dependency "ffi"
  spec.add_dependency "pry"

  spec.add_development_dependency "bundler", "~> 1.8"
  spec.add_development_dependency "rake", "~> 10.0"
  spec.add_development_dependency "rake-compiler"
end
