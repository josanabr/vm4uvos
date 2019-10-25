# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
  config.vm.define "master" do |m|
  	m.vm.box = "ubuntu/xenial64"
        m.vm.hostname = "vm4uvos.localhost"
        m.vm.provision "docker"
  	m.vm.provider :virtualbox do |vb|
		vb.customize [ 'modifyvm', :id, '--memory', '2048' ]
		vb.customize [ 'modifyvm', :id, '--cpus', '2' ]
		vb.customize [ 'modifyvm', :id, '--name', 'vm4uvos' ]
  	end
  end
end
