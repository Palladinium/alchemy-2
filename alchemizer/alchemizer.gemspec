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

  spec.files = `git ls-files -z -- .`.split("\x0").reject { |f| f.match(%r{^./(test|spec|features)/}) } +
               `git ls-files -z -- sources`.split("\x0")
  spec.require_paths = ['lib']

  spec.add_runtime_dependency 'polyglot'
  spec.add_runtime_dependency 'thor'
  spec.add_runtime_dependency 'treetop'
end
