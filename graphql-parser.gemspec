# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'graphql/parser/version'

Gem::Specification.new do |spec|
  spec.name          = 'graphql-parser'
  spec.version       = Graphql::Parser::VERSION
  spec.authors       = ['Evan Huus']
  spec.email         = ['evan.huus@shopify.com']
  spec.summary       = "Ruby bindings for Facebook's libgraphqlparser."
  spec.license       = 'BSD-3-Clause'

  spec.files         = `git ls-files -z`.split("\x0")
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ['lib']

  spec.add_development_dependency 'bundler', '~> 1.7'
  spec.add_development_dependency 'rake', '~> 10.0'
  spec.add_development_dependency 'rake-compiler', '~> 0.9'
  spec.add_development_dependency 'minitest', '~> 5.8'
end
