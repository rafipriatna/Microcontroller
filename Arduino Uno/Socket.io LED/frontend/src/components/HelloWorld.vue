<template>
  <div class="hello">
    <h1>{{ msg }}</h1>
    <p>
      Ini adalah aplikasi untuk berkomunikasi dengan Arduino Uno dengan Socket.Io sederhana. <br/> Untuk menyalakan lampu LED.
    </p>
    <h3>LED</h3>
    <ul>
      <li>
        LED Red
        <div class="custom-control custom-switch">
          <input type="checkbox" class="custom-control-input" id="ledRed" @change="switchRed($event)">
          <label class="custom-control-label" for="ledRed"></label>
        </div>
      </li>
      <li>
        LED Yellow
        <div class="custom-control custom-switch">
          <input type="checkbox" class="custom-control-input" id="ledYellow" @change="switchYellow($event)">
          <label class="custom-control-label" for="ledYellow"></label>
        </div>
      </li>
      <li>
        LED Green
        <div class="custom-control custom-switch">
          <input type="checkbox" class="custom-control-input" id="ledGreen" @change="switchGreen($event)">
          <label class="custom-control-label" for="ledGreen"></label>
        </div>
      </li>
    </ul>
  </div>
</template>

<script>
export default {
  name: 'HelloWorld',
  props: {
    msg: String
  },
  sockets: {
    connect: function () {
        console.log('socket connected')
    },
    customEmit: function () {
        console.log('this method was fired by the socket server.')
    }
  },
  data: () => {
    return {
      redState: 1,
      yellowState: 1,
      greenState: 1,
    }
  },
  methods: {
    switchRed: function() {
      this.$socket.emit("switchRed",this.redState)
      this.redState = !this.redState
    },
    switchYellow: function() {
      this.$socket.emit("switchYellow", this.yellowState);
      this.yellowState = !this.yellowState
    },
    switchGreen: function() {
      this.$socket.emit("switchGreen", this.greenState);
      this.greenState = !this.greenState
    },
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
h3 {
  margin: 40px 0 0;
}
ul {
  list-style-type: none;
  padding: 0;
}
li {
  display: inline-block;
  margin: 0 10px;
}
a {
  color: #42b983;
}
</style>
