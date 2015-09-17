require 'bundler/gem_tasks'
require 'rake/extensiontask'
require 'rake/testtask'

Rake::TestTask.new(test: :compile) do |t|
  t.test_files = FileList['test/**/*_test.rb']
end

Rake::ExtensionTask.new 'graphql_parser'

desc 'Run tests'
task default: :test
