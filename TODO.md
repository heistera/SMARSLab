# TODO
Full backlog available on our [Trello page](https://trello.com/b/R64x7GJG/smarslab)

- [ ] SM0012 - Replace telemetry and history with jquery dynamic data
- [ ] SM0013 - add more telemetry - the foot position and ultrasonic distance sensor data
- [ ] FIXME: create a blank smarslabdb.db, if this is to be usedself.
- [x] TODO: remove the forms.py user login stuff
- [ ] TODO: add a smars graphic to the page, depdending on what type is selected.
- [x] TODO: Add smars to pypy (smars_library is on Pypy) [smars_library](https://pypi.org/project/smars-library/)

---

### New Endpoints [COMPLETE]
- [x] Replace existing endpoint calls with single Post to control API
- [x] New endpoint for commands
- [x] New endpoint for getting telemetry in JSON
- [x] New endpoint for getting command history in JSON


### Setup page [IN PROGRESS]
- [x] Create a config.yml file for configuration
- [ ] Create a config page, read and writes config to config.yml

### Setup instructions

- [ ] Check the range of each servo is setup correctly
- [ ] Screw in the servo horn
- [ ] Check it can stand and sit
- [ ] Check it can walk forwards and backwards
- [ ] Check it can turn left
- [ ] Check it can turn right
---

### Images needed

- [ ] A picture of the raspberry pi wiring
- [ ] A picture of the range (maybe a video/GIF)
---

### Investigate other JS frameworks
- [ ] Use of grister.js
- [ ] Use of bootbox.js
---

### Detect Bluetooth SMARS
- [ ] Add bluetooth detection - difficult as no single bluetooth module works across windows/mac/linux
- [ ] Send commands to Bluetooth SMARS
- [ ] Add multiple SMARS
- [ ] Control multiple SMARS
---

### One tab per SMARS Robot

### Add rangefinder input via fundumoto connection
 - return via a bluetooth command
