import yaml

def yaml_loader(filepath):
  """ loads the yaml file """
  with open(filepath, "r") as file_descriptor:
      data = yaml.load(file_descriptor, Loader=yaml.SafeLoader)
  return data

def yaml_dump(filepath, data):
    """ Dumps data to a yaml file """
    with open(filepath, "w") as file_descriptor:
        yaml_dump(data, file_descriptor)

if __name__ == "__main__":
    file_path = "config.yml"
    data = yaml_loader(file_path)
    print(data)
