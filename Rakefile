require "bundler/gem_tasks"
require "rake/extensiontask"
require 'rake/testtask'

Rake::TestTask.new do |t|
    t.test_files = FileList['test/**/*_test.rb']
end

Rake::ExtensionTask.new "graphql_parser" do |ext|
    ext.lib_dir = "lib/graphql_parser"
end

desc 'Run tests'
task :default => :test
