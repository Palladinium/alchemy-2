# frozen_string_literal: true

Gem::Specification.new do |spec|
  spec.name        = 'alchemizer'
  spec.version     = '0.0.0'
  spec.summary     = 'Wrapper around alchemy 2'
  spec.description = 'Wrapper around alchemy 2'
  spec.authors     = ['Patrick Chieppe']
  spec.email       = 'patrick.chieppe@any.edu.au'

  # Prevent pushing this gem to RubyGems.org. To allow pushes either set the 'allowed_push_host'
  # to allow pushing to a single host or delete this section to allow pushing to any host.
  raise 'RubyGems 2.0 or newer is required' unless spec.respond_to?(:metadata)

  spec.metadata['allowed_push_host'] = "TODO: Set to 'http://mygemserver.com'"
  spec.metadata['rubygems_mfa_required'] = 'true'

  spec.files = Dir.glob('lib/*.rb') + Dir.glob('lib/grammars/treetop/*.tt')

  spec.required_ruby_version = File.read(File.join(File.dirname(__FILE__), '.ruby-version'))

  spec.add_runtime_dependency 'polyglot', '~> 0.3.5'
  spec.add_runtime_dependency 'thor', '~> 1.2.1'
  spec.add_runtime_dependency 'treetop', '~> 1.6.11'
end
